; Define constants
small_coffee_btn equ 0x01
medium_coffee_btn equ 0x02
large_coffee_btn equ 0x04
heating_element_pin equ 0x01

; Initialize the coffee machine
start:
    mov 0x00, heating_element_pin  ; Turn off heating element
    jmp wait_for_button_press

; Wait for a button press
wait_for_button_press:
    in 0x02, acc  ; Read the button state
    and small_coffee_btn, acc  ; Check if small coffee button is pressed
    jz wait_for_button_press  ; If not pressed, wait for next button press
    jmp make_small_coffee

; Make a small cup of coffee
make_small_coffee:
    mov 0x01, heating_element_pin  ; Turn on heating element
    delay 10  ; Wait for water to heat up
    mov 0x00, heating_element_pin  ; Turn off heating element
    jmp start  ; Start over

; Make a medium cup of coffee
make_medium_coffee:
    mov 0x01, heating_element_pin  ; Turn on heating element
    delay 15  ; Wait for water to heat up
    mov 0x00, heating_element_pin  ; Turn off heating element
    jmp start  ; Start over

; Make a large cup of coffee
make_large_coffee:
    mov 0x01, heating_element_pin  ; Turn on heating element
    delay 20  ; Wait for water to heat up
    mov 0x00, heating_element_pin  ; Turn off heating element
    jmp start  ; Start over