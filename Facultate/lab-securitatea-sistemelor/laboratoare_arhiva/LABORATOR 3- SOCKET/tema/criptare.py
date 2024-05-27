from PIL import Image

def encode_image(image_path, secret_image_path, output_path):
    # Open the original image
    original_image = Image.open(image_path)

    # Open the secret image
    secret_image = Image.open(secret_image_path)

    # Ensure that the secret image fits within the original image
    if secret_image.size[0] > original_image.size[0] or secret_image.size[1] > original_image.size[1]:
        raise ValueError("Secret image dimensions must be smaller than the original image")

    # Overlay the secret image onto the original image
    original_image.paste(secret_image, (0, 0))

    # Save the result
    original_image.save(output_path)
    print("Image encoded successfully.")

# Example usage:
encode_image("pic1.jpg", "pic2.jpg", "encoded_image.png")
