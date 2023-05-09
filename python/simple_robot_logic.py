# A simple robot program that moves forward, turns left, and moves forward again

# Import the necessary libraries
import time

# Define the robot class
class Robot:
    def __init__(self):
        self.position = (0, 0)
        self.orientation = 0

    def move_forward(self, distance):
        x = self.position[0] + distance * math.cos(self.orientation)
        y = self.position[1] + distance * math.sin(self.orientation)
        self.position = (x, y)

    def turn_left(self, angle):
        self.orientation += angle

# Create a new robot object
my_robot = Robot()

# Move the robot forward
my_robot.move_forward(10)

# Turn the robot left
my_robot.turn_left(math.pi/2)

# Move the robot forward again
my_robot.move_forward(10)

# Print the robot's current position and orientation
print("Robot position:", my_robot.position)
print("Robot orientation:", my_robot.orientation)

# In this example, the Robot class is defined with methods for moving the robot forward and turning it left. The move_forward method calculates the new position of the robot based on its current position and orientation, and the turn_left method updates the robot's orientation by a given angle.

# Then, a new Robot object is created and the robot is moved forward, turned left, and moved forward again. Finally, the robot's current position and orientation are printed to the console.

# This is just a simple example, but more complex robot logic can be built using Python, depending on the specific requirements of the robot and its task.