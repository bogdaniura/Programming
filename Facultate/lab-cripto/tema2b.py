def encrypt_text(key, text):
    encrypted_text = ''

    for letter in text:
        if letter == ' ':
            encrypted_text += 'W'
        else:
            for k, v in key.items():
                if letter in v:
                    encrypted_text += str(k)

    return encrypted_text


def decrypt_text(key, text):
    decrypted_text = ''

    two_numbers = ''

    for char in text:
        if char == 'W':
            decrypted_text += ' '
        else:
            two_numbers += char
            if len(two_numbers) == 2:
                decrypted_text += key[int(two_numbers)][0]
                two_numbers = ''

    return decrypted_text


text_to_encrypt = 'YOU SAY I USED TO BE WILD I SAY I USED TO BE YOUNG'
text_to_decrypt = '35525244251524141525524524522134122415'
key = {11: ['A'], 12: ['B'], 13: ['C'], 14: ['D'], 15: ['E'],
       21: ['F'], 22: ['G'], 23: ['H'], 24: ['I', 'J'], 25: ['K'],
       31: ['L'], 32: ['M'], 33: ['N'], 34: ['O'], 35: ['P'],
       41: ['Q'], 42: ['R'], 43: ['S'], 44: ['T'], 45: ['U'],
       51: ['V'], 52: ['W'], 53: ['X'], 54: ['Y'], 55: ['Z'], }

encrypted_text = encrypt_text(key, text_to_encrypt)

print(f'Encrypted text: {encrypted_text}')

decrypted_text = decrypt_text(key, text_to_decrypt)

print(f'Decrypted text: {decrypted_text}')
