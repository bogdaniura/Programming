from PIL import Image

def decode_image(encoded_image_path, output_path):
    # Open the encoded image
    encoded_image = Image.open(encoded_image_path)

    # Check if the image has an alpha channel
    if encoded_image.mode == 'RGBA':
        # If it has an alpha channel, remove it
        encoded_image = encoded_image.convert('RGB')

    # Save the resulting image as the extracted secret image
    encoded_image.save(output_path)
    print("Image decoded successfully.")

# Example usage:
decode_image("encoded_image.png", "decoded_secret_image.png")
