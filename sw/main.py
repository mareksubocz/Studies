import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)

# left bar
GPIO.setup(2, GPIO.OUT)
GPIO.setup(3, GPIO.OUT)
GPIO.setup(4, GPIO.OUT)
left_bar = [2, 3, 4]

# right bar
GPIO.setup(14, GPIO.OUT)
GPIO.setup(15, GPIO.OUT)
GPIO.setup(17, GPIO.OUT)
right_bar = [14, 15, 17]

# board positive
positives = [17, 27, 22, 26]
GPIO.setup(17, GPIO.OUT)
GPIO.setup(27, GPIO.OUT)
GPIO.setup(22, GPIO.OUT)
GPIO.setup(26, GPIO.OUT)

# board negative
GPIO.setup(22, GPIO.OUT)
GPIO.setup(23, GPIO.OUT)
GPIO.setup(24, GPIO.OUT)
GPIO.setup(25, GPIO.OUT)
negatives = [22, 23, 24, 25]

# left button
GPIO.setup(4, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
left_button = 11
# right button
GPIO.setup(25, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
right_button = 27

# maks 16 mA, 3.3 V
# 330 ohm resistor?

paddle_l = 1  # 2 - UP, 1 - MID, 0 - DOWN
paddle_r = 1
score_l = 0
score_r = 0

ball_pos = [1, 1]
direction = [1, -1]  # right and down
sleep_time = 0.5


def check_paddle_bounces():
    global ball_pos, paddle_l, paddle_r, direction
    # lewa strona
    if ball_pos[0] == 0 and direction[0] == -1:
        # w dół
        if direction[1] == -1 and paddle_l == ball_pos[1] - 1:
            ball_pos[1] -= 1
            direction[0] = 1
        # w górę
        elif direction[1] == 1 and paddle_l == ball_pos[1]:
            ball_pos[1] += 1
            direction[0] = 1
    # prawa strona
    elif ball_pos[0] == 3 and direction[0] == 1:
        # w dół
        if direction[1] == -1 and paddle_l == ball_pos[1] - 1:
            ball_pos[1] -= 1
            direction[0] = -1
        # w górę
        elif direction[1] == 1 and paddle_l == ball_pos[1]:
            ball_pos[1] += 1
            direction[0] = -1


def draw_paddles():
    global left_bar, right_bar, paddle_l, paddle_r
    for i in left_bar + right_bar:
        GPIO.output(i, GPIO.LOW)
    GPIO.output(left_bar[paddle_l], GPIO.HIGH)
    GPIO.output(right_bar[paddle_r], GPIO.HIGH)


def draw_ball():
    global ball_pos, positives, negatives
    for i in positives:
        GPIO.output(i, GPIO.LOW)
    for i in negatives:
        GPIO.output(i, GPIO.HIGH)

    # FIXME sprawdz czy dobre ball_pos
    GPIO.output(positives[ball_pos[0]], GPIO.HIGH)
    GPIO.output(negatives[ball_pos[1]], GPIO.LOW)


# left - przez kogo gol strzelony
def goal(by_left=True):
    global ball_pos, score_l, score_r, direction

    if by_left:
        score_l += 1
        ball_pos = [1, 2]
        direction = [1, 1]
    else:
        score_r += 1
        ball_pos = [2, 1]
        direction = [-1, -1]

    # show score for left
    for i, pin in enumerate(left_bar):
        if i < score_l:
            GPIO.output(pin, GPIO.HIGH)
        else:
            GPIO.output(pin, GPIO.LOW)

    # show score for right
    for i, pin in enumerate(right_bar):
        if i < score_r:
            GPIO.output(pin, GPIO.HIGH)
        else:
            GPIO.output(pin, GPIO.LOW)
    sleep(2)

    # reset game
    if score_l == 3 or score_r == 3:
        score_l = 0
        score_r = 0
        for pin in right_bar + left_bar:
            GPIO.output(pin, GPIO.LOW)
        sleep(2)


num_of_loops = 5
divider = 1.5

try:
    while True:
        for i in range(int(num_of_loops)):
            # wykrycie guzika lewego
            if GPIO.input(left_button) == GPIO.HIGH:
                paddle_l = (paddle_l + 1) % 3
            # wykrycie guzika prawego
            if GPIO.input(right_button) == GPIO.HIGH:
                paddle_r = (paddle_r + 1) % 3

            draw_paddles()

            # odbija się od górnej ściany
            if direction[1] == 1 and ball_pos[1] == 0:
                direction[1] = -1
            # odbija się od dolnej ściany
            elif direction[1] == -1 and ball_pos[1] == 3:
                direction[1] = 1

            check_paddle_bounces()

            ball_pos[0] += direction[0]
            ball_pos[1] += direction[1]

            if ball_pos[0] < 0:
                goal(by_left=False)
            elif ball_pos[0] > 3:
                goal(by_left=True)

            draw_ball()

            sleep(sleep_time)
        sleep_time /= divider
        num_of_loops *= divider
finally:
    GPIO.cleanup()
