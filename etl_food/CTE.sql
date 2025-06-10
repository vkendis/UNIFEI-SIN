WITH produtos_com_detalhes AS (
    SELECT 
        p.codigo,
        p.nome AS nome_produto,
        p.nutriscore,
        p.ecoscore,
        p.novascore,
        pm.marca_id,
        pi.ingrediente_id,
        pn.nutriente_id,
        pt.tag_id,
        pc.categoria_id
    FROM produto p
    LEFT JOIN produto_marca pm ON p.codigo = pm.produto_id
    LEFT JOIN produto_ingrediente pi ON p.codigo = pi.produto_id
    LEFT JOIN produto_nutriente pn ON p.codigo = pn.produto_id
    LEFT JOIN produto_tag pt ON p.codigo = pt.produto_id
    LEFT JOIN produto_categoria pc ON p.codigo = pc.produto_id
),
detalhes_expandidos AS (
    SELECT 
        p.codigo,
        p.nome_produto,
        m.nome AS nome_marca,
        i.nome AS nome_ingrediente,
        n.nome AS nome_nutriente,
        n.unidade,
        t.nome AS nome_tag,
        t.tipo AS tipo_tag,
        c.nome AS nome_categoria
    FROM produtos_com_detalhes p
    LEFT JOIN marca m ON m.id = p.marca_id
    LEFT JOIN ingrediente i ON i.id = p.ingrediente_id
    LEFT JOIN nutriente n ON n.id = p.nutriente_id
    LEFT JOIN tag t ON t.id = p.tag_id
    LEFT JOIN categoria c ON c.id = p.categoria_id
)
SELECT 
    codigo,
    nome_produto,
    nome_marca,
    nome_ingrediente,
    nome_nutriente,
    unidade,
    nome_tag,
    tipo_tag,
    nome_categoria,
    COUNT(*) OVER (PARTITION BY codigo) AS complexidade_relacional,
    random() * 1000 AS pontuacao_fake 
FROM detalhes_expandidos
ORDER BY random()
LIMIT 5000;
