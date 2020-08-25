import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="12345678",
  database="Node"
)

mycursor = mydb.cursor()

mycursor.execute("SELECT * FROM NodePacketData")

myresult = mycursor.fetchone()

print(myresult[2])
