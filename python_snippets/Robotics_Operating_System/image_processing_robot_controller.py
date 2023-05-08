#!/usr/bin/env python

import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy

class RobotController:
    def __init__(self):
        self.bridge = CvBridge()
        self.joy_sub = rospy.Subscriber('/joy', Joy, self.joy_callback)
        self.image_sub = rospy.Subscriber('/camera/image_raw', Image, self.camera_callback)
        self.cmd_vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
        self.move_cmd = Twist()

        self.image_processing_enabled = True
        self.object_detected = False

        # Initialize the OpenCV object detection classifier
        self.object_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

    def joy_callback(self, joy_msg):
        if joy_msg.buttons[0] == 1: # A button pressed
            self.image_processing_enabled = not self.image_processing_enabled
            rospy.loginfo(f"Image processing {'enabled' if self.image_processing_enabled else 'disabled'}")

    def camera_callback(self, image_msg):
        if self.image_processing_enabled:
            # Convert the ROS Image message to a OpenCV image
            cv_image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")

            # Convert the image to grayscale
            gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)

            # Detect objects in the image
            objects = self.object_cascade.detectMultiScale(gray, scaleFactor=1.3, minNeighbors=5)

            # Draw rectangles around the detected objects
            for (x, y, w, h) in objects:
                cv2.rectangle(cv_image, (x, y), (x+w, y+h), (0, 255, 0), 2)
                self.object_detected = True

            # Publish the processed image to a ROS topic
            image_processed = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
            self.image_pub.publish(image_processed)

        # If an object is detected, stop the robot
        if self.object_detected:
            self.move_cmd.linear.x = 0.0
            self.move_cmd.angular.z = 0.0
            self.cmd_vel_pub.publish(self.move_cmd)
            rospy.loginfo("Object detected, stopping robot.")

    def run(self):
        rospy.spin()

if __name__ == '__main__':
    rospy.init_node('robot_controller')
    robot_controller = RobotController()
    robot_controller.run()


# This code uses the "haarcascade_frontalface_default.xml" classifier to detect faces in the camera image. 
# 
# When a face is detected, it sets a flag (self.object_detected) which causes the robot to stop moving. 
# 
# You can modify the code to perform other image processing tasks, such as "image segmentation", by replacing the "object detection" code with your "own processing" code.
