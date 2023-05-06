#!/usr/bin/env python

import rospy
from std_msgs.msg import String
import mysql.connector

# Define the name of the tongue sensor topic
tongue_sensor_topic = "/tongue/sensor"

# Connect to the SQL database
mydb = mysql.connector.connect(
  host="localhost",
  user="yourusername",
  password="yourpassword",
  database="mydatabase"
)

# Create a cursor object to execute SQL queries
mycursor = mydb.cursor()

# Define a function to handle tongue sensor data
def tongue_sensor_callback(data):
    # Extract the cuisine name and taste from the message
    msg = data.data
    cuisine, taste = msg.split(",")

    # Insert the cuisine name and taste into the SQL database
    sql = "INSERT INTO cuisines (cuisine_name, taste) VALUES (%s, %s)"
    val = (cuisine, taste)
    mycursor.execute(sql, val)
    mydb.commit()

    # Print a message indicating that the cuisine was registered in the database
    rospy.loginfo("Registered cuisine %s with taste %s in the database", cuisine, taste)

def tongue_sensor_listener():
    # Initialize the ROS node
    rospy.init_node('tongue_sensor_listener', anonymous=True)

    # Subscribe to the tongue sensor topic
    rospy.Subscriber(tongue_sensor_topic, String, tongue_sensor_callback)

    # Spin the node to keep it alive
    rospy.spin()

if __name__ == '__main__':
    try:
        tongue_sensor_listener()
    except rospy.ROSInterruptException:
        pass


# Note that this example assumes that you have already created an SQL database named "mydatabase" and a table named "cuisines" with columns "cuisine_name" and "taste". You would need to modify this code to use the appropriate database credentials and table schema for your setup.
