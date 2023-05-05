import rospy
from std_msgs.msg import Float64

class EyeController:
    def __init__(self):
        # Initialize ROS node and subscribers/publishers
        rospy.init_node('eye_controller')
        self.eye_position_sub = rospy.Subscriber('/eye_position', Float64, self.eye_position_callback)
        self.eye_movement_pub = rospy.Publisher('/eye_movement', Float64, queue_size=10)

    def eye_position_callback(self, data):
        # Get eye position and publish eye movement
        eye_movement = calculate_eye_movement(data)
        self.eye_movement_pub.publish(eye_movement)

def calculate_eye_movement(eye_position):
    # Calculate eye movement based on eye position
    eye_movement = eye_position * 2  # simple example
    return eye_movement

if __name__ == '__main__':
    ec = EyeController()
    rospy.spin()


# Explanatory comments:
# Here are the basic steps to create eye control code using ROS:

# 1) Install ROS and Python on your system, if not already installed.
# 2) Install the ROS packages needed for eye control. The ROS packages for controlling eyes are typically part of the robot’s specific hardware package, so you will need to identify the package for your robot.
# 3) Connect your eye hardware to the computer running ROS.
# 4) Write Python code to communicate with the eye hardware using ROS commands. The code should subscribe to messages from the eye hardware, such as eye position and movement commands, and publish messages back to the hardware to control the movement of the eyes.
# 5) Test and debug your eye control code using ROS tools such as rostopic and rosservice commands.


# How the above written code works?

# The above code creates a ROS node called 'eye_controller' and subscribes to the '/eye_position' topic, which provides the current position of the eyes. It then calculates the desired eye movement based on the current position and publishes it to the '/eye_movement' topic. The calculate_eye_movement function can be customized to calculate the eye movement based on the specific hardware used.

# Note: this is just a simple example, and the actual code for controlling eyes will be more complex and specific to the robot hardware used.
