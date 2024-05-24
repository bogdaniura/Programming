# Import Image from PIL module using the import keyword
from PIL import Image
# Import stepic module using the import keyword
import stepic
# Open the image from which you want to extract the secret message(encrypted image) using the
# open() function by passing filename/path as an argument to it.
# Store it in a variable
encryptd_image = Image.open("EncryptedImage.png")
# Pass the above encrypted image to the decode() function of the stepic module 
# to give the encrypted secret message in the string format.
# Store it in another variable
decryptedmessage = stepic.decode(encryptd_image)
# Print some random text for acknowledgment
print("Decryption has done successfully")
# Print the decrypted/decoded message
print("The decrypted message = ", decryptedmessage)