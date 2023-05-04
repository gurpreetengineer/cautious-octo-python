#!/usr/bin/env python

import rospy
from std_msgs.msg import Float64
from sensor_msgs.msg import JointState

def arm_joint_callback(joint_state):
    # Read joint state values for the arm
    arm_joint1 = joint_state.position[0]
    arm_joint2 = joint_state.position[1]
    arm_joint3 = joint_state.position[2]
    arm_joint4 = joint_state.position[3]
    arm_joint5 = joint_state.position[4]
    arm_joint6 = joint_state.position[5]

    # Control the arm joints
    arm_joint1_pub.publish(0.5)
    arm_joint2_pub.publish(0.7)
    arm_joint3_pub.publish(1.0)
    arm_joint4_pub.publish(1.2)
    arm_joint5_pub.publish(1.5)
    arm_joint6_pub.publish(1.7)

def finger_joint_callback(joint_state):
    # Read joint state values for the fingers
    finger_joint1 = joint_state.position[0]
    finger_joint2 = joint_state.position[1]
    finger_joint3 = joint_state.position[2]

    # Control the finger joints
    finger_joint1_pub.publish(0.2)
    finger_joint2_pub.publish(0.4)
    finger_joint3_pub.publish(0.6)

if __name__ == '__main__':
    # Initialize ROS node
    rospy.init_node('robotic_arm_control_node')

    # Initialize publishers for controlling the arm joints
    arm_joint1_pub = rospy.Publisher('/arm/joint1_position_controller/command', Float64, queue_size=10)
    arm_joint2_pub = rospy.Publisher('/arm/joint2_position_controller/command', Float64, queue_size=10)
    arm_joint3_pub = rospy.Publisher('/arm/joint3_position_controller/command', Float64, queue_size=10)
    arm_joint4_pub = rospy.Publisher('/arm/joint4_position_controller/command', Float64, queue_size=10)
    arm_joint5_pub = rospy.Publisher('/arm/joint5_position_controller/command', Float64, queue_size=10)
    arm_joint6_pub = rospy.Publisher('/arm/joint6_position_controller/command', Float64, queue_size=10)

    # Initialize publishers for controlling the finger joints
    finger_joint1_pub = rospy.Publisher('/finger/joint1_position_controller/command', Float64, queue_size=10)
    finger_joint2_pub = rospy.Publisher('/finger/joint2_position_controller/command', Float64, queue_size=10)
    finger_joint3_pub = rospy.Publisher('/finger/joint3_position_controller/command', Float64, queue_size=10)

    # Initialize subscriber for reading arm joint states
    rospy.Subscriber('/arm/joint_states', JointState, arm_joint_callback)

    # Initialize subscriber for reading finger joint states
    rospy.Subscriber('/finger/joint_states', JointState, finger_joint_callback)

    # Spin the ROS node
    rospy.spin()
