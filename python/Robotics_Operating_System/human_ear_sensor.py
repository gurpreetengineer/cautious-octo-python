#!/usr/bin/env python

import rospy
import sqlite3
from std_msgs.msg import String
from sensor_msgs.msg import AudioData
from math import floor

# Define the name of the ear sensor topic
ear_sensor_topic = "/ear_sensor"

# Define the name of the SQL database
database_file = "voice_data.db"

# Define the SQL query to insert voice data
insert_query = "INSERT INTO voice_data (frequency, wavelength, pitch) VALUES (?, ?, ?)"

# Create a connection to the SQL database
conn = sqlite3.connect(database_file)
c = conn.cursor()

# Create the voice_data table if it doesn't already exist
c.execute('''CREATE TABLE IF NOT EXISTS voice_data (id INTEGER PRIMARY KEY, frequency REAL, wavelength REAL, pitch REAL)''')

# Function to calculate the wavelength of a sound wave
def calculate_wavelength(sample_rate, frequency):
    return sample_rate / frequency

# Function to calculate the pitch of a sound wave
def calculate_pitch(wavelength):
    return 1.0 / wavelength

# Callback function for the ear sensor topic
def ear_sensor_callback(data):
    # Extract the sample rate and audio data from the message
    sample_rate = data.sample_rate
    audio_data = data.data

    # Calculate the frequency, wavelength, and pitch of the audio data
    frequency = floor(len(audio_data) / 2.0) / len(audio_data) * sample_rate
    wavelength = calculate_wavelength(sample_rate, frequency)
    pitch = calculate_pitch(wavelength)

    # Insert the voice data into the SQL database
    c.execute(insert_query, (frequency, wavelength, pitch))
    conn.commit()

def ear_sensor_subscriber():
    # Initialize the ROS node
    rospy.init_node('ear_sensor_subscriber', anonymous=True)

    # Create a subscriber for the ear sensor topic
    rospy.Subscriber(ear_sensor_topic, AudioData, ear_sensor_callback)

    rospy.spin()

if __name__ == '__main__':
    try:
        ear_sensor_subscriber()
    except rospy.ROSInterruptException:
        pass

# Close the SQL database connection when the program exits
conn.close()

# In this example, we define an ear sensor topic and an SQL database file. We then define an SQL query to insert voice data and create a connection to the database. We also define functions to calculate the wavelength and pitch of a sound wave.

# In the ear_sensor_callback function, we extract the sample rate and audio data from the message, calculate the frequency, wavelength, and pitch of the audio data, and insert the voice data into the SQL database using the SQL query we defined earlier.

# Finally, we initialize the ROS node, create a subscriber for the ear sensor topic, and run the subscriber indefinitely using rospy.spin(). We also close the SQL database connection when the program exits.

# Note that this example assumes that the ear sensor topic publishes sensor_msgs/AudioData messages. You may need to modify this code to work with a different type of ear sensor message. Also, the wavelength calculation assumes that the sound wave is a pure sine wave, which may not be true in all cases.
