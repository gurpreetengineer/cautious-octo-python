# Raspberry pi example code for remote control car

import RPi.GPIO as GPIO
import time

# Set up pins
GPIO.setmode(GPIO.BOARD)

motor1_pin1 = 7
motor1_pin2 = 11
motor1_pwm_pin = 12
motor2_pin1 = 13
motor2_pin2 = 15
motor2_pwm_pin = 16

GPIO.setup(motor1_pin1, GPIO.OUT)
GPIO.setup(motor1_pin2, GPIO.OUT)
GPIO.setup(motor1_pwm_pin, GPIO.OUT)
GPIO.setup(motor2_pin1, GPIO.OUT)
GPIO.setup(motor2_pin2, GPIO.OUT)
GPIO.setup(motor2_pwm_pin, GPIO.OUT)

motor1_pwm = GPIO.PWM(motor1_pwm_pin, 50)
motor2_pwm = GPIO.PWM(motor2_pwm_pin, 50)

# Define functions for controlling car
def forward():
    GPIO.output(motor1_pin1, GPIO.HIGH)
    GPIO.output(motor1_pin2, GPIO.LOW)
    GPIO.output(motor2_pin1, GPIO.HIGH)
    GPIO.output(motor2_pin2, GPIO.LOW)
    motor1_pwm.start(50)
    motor2_pwm.start(50)

def backward():
    GPIO.output(motor1_pin1, GPIO.LOW)
    GPIO.output(motor1_pin2, GPIO.HIGH)
    GPIO.output(motor2_pin1, GPIO.LOW)
    GPIO.output(motor2_pin2, GPIO.HIGH)
    motor1_pwm.start(50)
    motor2_pwm.start(50)

def left():
    GPIO.output(motor1_pin1, GPIO.LOW)
    GPIO.output(motor1_pin2, GPIO.HIGH)
    GPIO.output(motor2_pin1, GPIO.HIGH)
    GPIO.output(motor2_pin2, GPIO.LOW)
    motor1_pwm.start(50)
    motor2_pwm.start(50)

def right():
    GPIO.output(motor1_pin1, GPIO.HIGH)
    GPIO.output(motor1_pin2, GPIO.LOW)
    GPIO.output(motor2_pin1, GPIO.LOW)
    GPIO.output(motor2_pin2, GPIO.HIGH)
    motor1_pwm.start(50)
    motor2_pwm.start(50)

def stop():
    GPIO.output(motor1_pin1, GPIO.LOW)
    GPIO.output(motor1_pin2, GPIO.LOW)
    GPIO.output(motor2_pin1, GPIO.LOW)
    GPIO.output(motor2_pin2, GPIO.LOW)
    motor1_pwm.stop()
    motor2_pwm.stop()

# Main loop for remote control
while True:
    command = input("Enter command (w-forward, s-backward, a-left, d-right, x-stop): ")
    if command == "w":
        forward()
    elif command == "s":
        backward()
    elif command == "a":
        left()
    elif command == "d":
        right()
    elif command == "x":
        stop()
        GPIO.cleanup()
        break
