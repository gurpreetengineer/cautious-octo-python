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
