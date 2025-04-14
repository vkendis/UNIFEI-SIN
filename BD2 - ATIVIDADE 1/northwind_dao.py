import psycopg2
from psycopg2.extensions import AsIs

class PedidoDAO:
    def __init__(self):
        self.conn_string = "host='localhost' dbname='nw' user='postgres' password='123' port='5433'"

    def testar_conexao(self):
        try:
            conexao = psycopg2.connect(self.conn_string)
            conexao.set_client_encoding('LATIN1')
            conexao.close()
            return True
        except Exception:
            return False

    def __iniciar_transacao(self):
        try:
            self.conexao = psycopg2.connect(self.conn_string)
            self.conexao.autocommit = False
        except psycopg2.Error as erro:
            print(f"Erro ao iniciar transação: {erro.pgcode} - {erro.pgerror}")

    def __confirmar_transacao(self):
        try:
            if self.conexao is not None:
                self.conexao.commit()
                self.conexao.close()
                self.conexao = None
        except psycopg2.Error as erro:
            print(f"Erro ao confirmar transação: {erro.pgcode} - {erro.pgerror}")

    def __desfazer_transacao(self):
        try:
            if self.conexao is not None:
                self.conexao.rollback()
                self.conexao.close()
                self.conexao = None
        except psycopg2.Error as erro:
            print(f"Erro ao desfazer transação: {erro.pgcode} - {erro.pgerror}")

    def buscar_pedido_completo(self, codigo_pedido):
        consulta = """
            SELECT 
                p.orderid, 
                p.orderdate, 
                cli.contactname AS nome_cliente, 
                emp.firstname AS nome_funcionario,
                det.productid, 
                det.unitprice, 
                det.quantity
            FROM northwind.orders p
            JOIN northwind.customers cli ON p.customerid = cli.customerid
            JOIN northwind.employees emp ON p.employeeid = emp.employeeid
            LEFT JOIN northwind.order_details det ON p.orderid = det.orderid
            WHERE p.orderid = %s;
        """
        return self.__executar_sql(consulta, (codigo_pedido,))

    def inserir_pedido(self, dados):
        self.__iniciar_transacao()
        try:
            comando_pedido = "INSERT INTO northwind.orders VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s);"
            self.__executar_sql(comando_pedido, dados['order'])

            comando_itens = "INSERT INTO northwind.order_details VALUES (%s, %s, %s, %s, %s);"
            for item in dados['order_details']:
                self.__executar_sql(comando_itens, item)

            self.__confirmar_transacao()
        except Exception as erro:
            self.__desfazer_transacao()
            raise erro

    def ranking_funcionarios(self):
        consulta = """
        SELECT emp.firstname, emp.hiredate, COUNT(ped.orderid), SUM(det.unitprice)
        FROM northwind.employees emp
        JOIN northwind.orders ped ON emp.employeeid = ped.employeeid
        JOIN northwind.order_details det ON ped.orderid = det.orderid
        GROUP BY emp.hiredate, emp.firstname
        ORDER BY emp.hiredate ASC;
        """
        return self.__executar_sql(consulta, ())

    def __executar_sql(self, comando, valores):
        erro_codigo = None
        total_afetado = 0
        registros = []
        cursor = None
        conexao = None
        try:
            conexao = psycopg2.connect(self.conn_string)
            cursor = conexao.cursor()
            cursor.execute("SET search_path TO northwind;")
            cursor.execute(comando, valores)
            total_afetado = cursor.rowcount
            conexao.commit()
            try:
                registros = cursor.fetchall()
            except:
                registros = []
        except psycopg2.Error as erro:
            erro_codigo = erro.pgcode
            print(f"Erro ao executar SQL: {erro.pgcode} - {erro.pgerror}")
            conexao.rollback()
        finally:
            if cursor is not None:
                cursor.close()
            if conexao is not None:
                conexao.close()

        return erro_codigo, total_afetado, registros
