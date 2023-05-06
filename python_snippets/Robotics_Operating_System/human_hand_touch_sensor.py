#!/usr/bin/env python

import rospy
from std_msgs.msg import Bool

# Define the names of the touch sensors
left_finger_1 = "/left_hand/finger_1/touch"
left_finger_2 = "/left_hand/finger_2/touch"
left_finger_3 = "/left_hand/finger_3/touch"
left_finger_4 = "/left_hand/finger_4/touch"
left_thumb = "/left_hand/thumb/touch"

right_finger_1 = "/right_hand/finger_1/touch"
right_finger_2 = "/right_hand/finger_2/touch"
right_finger_3 = "/right_hand/finger_3/touch"
right_finger_4 = "/right_hand/finger_4/touch"
right_thumb = "/right_hand/thumb/touch"

def touch_sensor_publisher():
    # Initialize the ROS node
    rospy.init_node('touch_sensor_publisher', anonymous=True)

    # Create publishers for each touch sensor
    left_finger_1_pub = rospy.Publisher(left_finger_1, Bool, queue_size=10)
    left_finger_2_pub = rospy.Publisher(left_finger_2, Bool, queue_size=10)
    left_finger_3_pub = rospy.Publisher(left_finger_3, Bool, queue_size=10)
    left_finger_4_pub = rospy.Publisher(left_finger_4, Bool, queue_size=10)
    left_thumb_pub = rospy.Publisher(left_thumb, Bool, queue_size=10)

    right_finger_1_pub = rospy.Publisher(right_finger_1, Bool, queue_size=10)
    right_finger_2_pub = rospy.Publisher(right_finger_2, Bool, queue_size=10)
    right_finger_3_pub = rospy.Publisher(right_finger_3, Bool, queue_size=10)
    right_finger_4_pub = rospy.Publisher(right_finger_4, Bool, queue_size=10)
    right_thumb_pub = rospy.Publisher(right_thumb, Bool, queue_size=10)

    rate = rospy.Rate(10) # Set the publishing rate to 10 Hz

    # Loop to simulate touch sensor data
    while not rospy.is_shutdown():
        # Simulate touch sensor data for the left hand
        left_finger_1_pub.publish(True)
        left_finger_2_pub.publish(False)
        left_finger_3_pub.publish(True)
        left_finger_4_pub.publish(False)
        left_thumb_pub.publish(True)

        # Simulate touch sensor data for the right hand
        right_finger_1_pub.publish(False)
        right_finger_2_pub.publish(True)
        right_finger_3_pub.publish(False)
        right_finger_4_pub.publish(True)
        right_thumb_pub.publish(False)

        rate.sleep()

if __name__ == '__main__':
    try:
        touch_sensor_publisher()
    except rospy.ROSInterruptException:
        pass


# Note that this example is just a simulation and does not actually read touch sensor data from physical sensors. You would need to modify this code to interface with actual touch sensors on your robot.
