import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="12345678",
  database="Node"
)

mycursor = mydb.cursor()

sql = "DROP TABLE customers"

mycursor.execute(sql)
