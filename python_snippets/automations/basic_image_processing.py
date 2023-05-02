from PIL import Image, ImageFilter

# Open the image file
image = Image.open('input_image.jpg')

# Convert the image to grayscale
grayscale_image = image.convert('L')

# Apply a blur filter to the grayscale image
blurred_image = grayscale_image.filter(ImageFilter.BLUR)

# Rotate the blurred image by 90 degrees
rotated_image = blurred_image.rotate(90)

# Save the rotated image to a file
rotated_image.save('output_image.jpg')
