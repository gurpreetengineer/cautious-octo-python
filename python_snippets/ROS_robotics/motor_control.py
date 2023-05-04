#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def motor_control(data):
    # This function is called whenever the subscribed topic receives a message
    # The data argument contains the message payload
    speed = data.data # Extract the speed value from the message payload
    # Use the speed value to control the motor
    # ...

def motor_node():
    # Initialize the ROS node for motor control
    rospy.init_node('motor_node', anonymous=True)
    # Create a subscriber to the "motor_speed" topic, with the callback function "motor_control"
    rospy.Subscriber('motor_speed', Int32, motor_control)
    # Start the node
    rospy.spin()

if __name__ == '__main__':
    motor_node()

# In this code, we create a ROS node called "motor_node" that subscribes to the "motor_speed" topic. Whenever a message is received on this topic, the "motor_control" function is called with the message payload as the argument. This function extracts the speed value from the message and uses it to control the motor.

# To use this code, you would need to have ROS installed on your system and a motor driver hardware connected to your system. You would also need to create a ROS publisher node that publishes messages on the "motor_speed" topic with the desired speed value.