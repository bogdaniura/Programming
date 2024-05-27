from PIL import Image

def decode_image(encoded_image_path, output_path):
    encoded_image = Image.open(encoded_image_path)

    if encoded_image.mode == 'RGBA':
        encoded_image = encoded_image.convert('RGB')

    encoded_image.save(output_path)
    print("Image decoded successfully.")

decode_image("encoded_image.png", "decoded_secret_image.png")
