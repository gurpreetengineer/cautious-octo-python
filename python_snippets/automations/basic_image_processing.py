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

# In this example, the program first opens an input image file using the Image.open() method from the Pillow library. 
# It then converts the image to grayscale using the convert() method with the 'L' mode. 
# 
# Next, the program applies a blur filter to the grayscale image using the filter() method with the ImageFilter.BLUR filter. 
# 
# It then rotates the blurred image by 90 degrees using the rotate() method. 
# Finally, the program saves the rotated image to a file using the save() method.

# Of course, this is just a simple example and there are many other image processing techniques you can apply using Python and 
# the Pillow library. 
# 
# You can experiment with different filters, color manipulations, and transformations to achieve different effects.
