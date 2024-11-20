import pandas as pd

# Carregamos o arquivo CSV com os dados
df = pd.read_csv("dataset_origin.csv", encoding="utf-8", sep=";", on_bad_lines='skip')

# Contamos os valores "Crm Cd Desc" que serão usados como filtragem, considerando os 17 mais relevantes
qtdValores = df["Crm Cd Desc"].value_counts().head(17).sum()

# Definimos a lista de valores desejados em "Crm Cd Desc"
crimes_considerados = [
    "VEHICLE - STOLEN",
    "BATTERY - SIMPLE ASSAULT",
    "BURGLARY FROM VEHICLE",
    "THEFT OF IDENTITY",
    "VANDALISM - FELONY ($400 & OVER, ALL CHURCH VANDALISMS)",
    "BURGLARY",
    "ASSAULT WITH DEADLY WEAPON, AGGRAVATED ASSAULT",
    "THEFT PLAIN - PETTY ($950 & UNDER)",
    "INTIMATE PARTNER - SIMPLE ASSAULT",
    "THEFT FROM MOTOR VEHICLE - PETTY ($950 & UNDER)",
    "THEFT FROM MOTOR VEHICLE - GRAND ($950.01 AND OVER)",
    "THEFT-GRAND ($950.01 & OVER)EXCPT,GUNS,FOWL,LIVESTK,PROD",
    "ROBBERY",
    "SHOPLIFTING - PETTY THEFT ($950 & UNDER)",
    "VANDALISM - MISDEAMEANOR ($399 OR UNDER)",
    "CRIMINAL THREATS - NO WEAPON DISPLAYED",
    "TRESPASSING"
]

# Filtramos os registros com base nos crimes considerados
df_Filtrado = df[df["Crm Cd Desc"].isin(crimes_considerados)]
print("O df_Filtrado foi filtrado corretamente? ", (df_Filtrado["Crm Cd Desc"].value_counts().sum() == qtdValores))

# Definimos as colunas que queremos manter
colunasMantidas = [
    "DR_NO",
    "Date Rptd",
    "TIME OCC",
    "AREA NAME",
    "Crm Cd",
    "Crm Cd Desc",
    "Vict Sex",
    "Premis Desc",
    "Weapon Used Cd",
    "Weapon Desc",
]

# Criamos uma cópia dos dados filtrados apenas com as colunas necessárias
dataFinal = df_Filtrado[colunasMantidas].copy()

# Função para categorizar o tempo em turnos
def categoriza_tempo(time_occ):
    time = int(time_occ)
    if 0 <= time <= 1200:
        return "Manhã"
    elif 1201 <= time <= 1800:
        return "Tarde"
    else:
        return "Noite"

# Formatamos o campo 'DATE RPTD' no formato MÊS/ANO
print("Formatando o campo 'DATE RPTD' no formato MÊS/ANO")
dataFinal.loc[:, 'Date Rptd'] = pd.to_datetime(dataFinal['Date Rptd'], errors='coerce').dt.strftime('%m/%y')

# Formatamos o campo 'TIME OCC' para representar turnos (Manhã, Tarde, Noite)
print("Formatando o campo 'TIME OCC' por turno (Manhã, Tarde, Noite)")
dataFinal['TIME OCC'] = dataFinal['TIME OCC'].apply(categoriza_tempo)

# Salvamos o arquivo CSV processado
csv_saida = "dataset_filtrado.csv"
dataFinal.to_csv(csv_saida, index=False, encoding="utf-8", sep=";")
print(f"Arquivo CSV '{csv_saida}' gerado com sucesso!")
