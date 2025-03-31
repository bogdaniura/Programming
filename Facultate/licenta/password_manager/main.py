import sqlite3
import os
import secrets
import string
from cryptography.fernet import Fernet

# 1. Generare si salvare cheie criptare
KEY_FILE = "key.key"
DB_FILE = "passwords.db"

def load_or_generate_key():
    if os.path.exists(KEY_FILE):
        with open(KEY_FILE, "rb") as file:
            return file.read()
    else:
        key = Fernet.generate_key()
        with open(KEY_FILE, "wb") as file:
            file.write(key)
        return key

KEY = load_or_generate_key()
cipher = Fernet(KEY)

# 2. Initializare baza de date
def init_db():
    conn = sqlite3.connect(DB_FILE)
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS passwords (
            id INTEGER PRIMARY KEY,
            service TEXT NOT NULL,
            username TEXT NOT NULL,
            password TEXT NOT NULL
        )
    ''')
    conn.commit()
    conn.close()

# 3. Functii pentru criptare/decriptare
def encrypt_password(password):
    return cipher.encrypt(password.encode())

def decrypt_password(encrypted_password):
    return cipher.decrypt(encrypted_password).decode()

# 4. Functie pentru adaugare parola
def store_password(service, username, password):
    encrypted_password = encrypt_password(password)
    conn = sqlite3.connect(DB_FILE)
    cursor = conn.cursor()
    cursor.execute("INSERT INTO passwords (service, username, password) VALUES (?, ?, ?)",
                   (service, username, encrypted_password))
    conn.commit()
    conn.close()
    print("✔ Parola salvata cu succes!")

# 5. Functie pentru cautare parole
def retrieve_password(service):
    conn = sqlite3.connect(DB_FILE)
    cursor = conn.cursor()
    cursor.execute("SELECT username, password FROM passwords WHERE service = ?", (service,))
    result = cursor.fetchone()
    conn.close()
    if result:
        username, encrypted_password = result
        decrypted_password = decrypt_password(encrypted_password)
        print(f"🔑 Service: {service}\n👤 Username: {username}\n🔒 Password: {decrypted_password}")
    else:
        print("❌ Nu exista inregistrari pentru acest serviciu.")

# 6. Functie pentru generare parole sigure
def generate_password(length=16):
    chars = string.ascii_letters + string.digits + string.punctuation
    return ''.join(secrets.choice(chars) for _ in range(length))

# 7. Test script
if __name__ == "__main__":
    init_db()
    print("1. Adauga parola\n2. Cauta parola\n3. Genereaza parola\n")
    choice = input("Alege optiunea: ")
    
    if choice == "1":
        service = input("Service: ")
        username = input("Username: ")
        password = input("Parola: ")
        store_password(service, username, password)
    elif choice == "2":
        service = input("Service: ")
        retrieve_password(service)
    elif choice == "3":
        length = int(input("Lungime parola: "))
        print("🔑 Parola generata:", generate_password(length))
    else:
        print("❌ Optiune invalida.")
