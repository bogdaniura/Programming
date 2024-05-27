# Import Image from PIL module using the import keyword
from PIL import Image
# Import stepic module using the import keyword
import stepic
# Open the image using the open() function of the Image module 
# by passing the image filename/path as an argument to it
# in which the secret message will be stored.
gvn_image = Image.open("./sampleimage.png")
# Give some random secret message and store it in a variable
secret_msg = "AM CODIFICAT ACEASTA IMAGINE"
# Convert the above given secret message into UTF-8 format using the encode() function
# and store it in the same variable
secret_msg = secret_msg.encode()
# Pass the given image and secret message into the encode() function of the stepic module
# which gives a new image within which the secret message is hidden.
encodedimage = stepic.encode(gvn_image, secret_msg)
# Save the above encoded/encrypted image with some random name and extension using the 
# save() function
encodedimage.save("EncryptedImage.png")
# Print some random text for acknowledgment
print("Encryption has done successfully")