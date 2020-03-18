import pygame
from draw_board import draw_board
# --- Globals ---
# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)


board = [[0, 0, 0, 4, 5, 0],
         [0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 1, 0],
         [0, 0, 0, 0, 0, 0],
         [0, 0, 2, 3, 0, 0]]

# Set the width and height of each snake segment
segment_width = 15
segment_height = 15
# Margin between each segment
segment_margin = 3


# for box in boxes:
#     if box.rect.collidepoint(x, y):
#         print 'yay!'


class Segment(pygame.sprite.Sprite):
    """ Class to represent one segment of the snake. """
    # -- Methods
    # Constructor function

    def __init__(self, x, y):
        # Call the parent's constructor
        super().__init__()

        # Set height, width
        self.image = pygame.Surface([segment_width, segment_height])
        self.image.fill(RED)

        # Make our top-left corner the passed-in location.
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y


# Call this function so the Pygame library can initialize itself
pygame.init()

# Create an 800x600 sized screen
screen = pygame.display.set_mode([700, 700])

# Set the title of the window
pygame.display.set_caption('Snake Example')

clock = pygame.time.Clock()
done = False

draw_board(screen, board)
while not done:

    for event in pygame.event.get():
        if event.type == pygame.QUIT or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
            done = True
        if event.type == pygame.MOUSEBUTTONDOWN:
            x, y = event.pos
            print(f"{x} {y}")
    # Set the speed based on the key pressed
    # We want the speed to be enough that we move a full
    # segment, plus the margin.
    # if event.type == pygame.KEYDOWN:
    #     if event.key == pygame.K_LEFT:
    #         x_change = (segment_width + segment_margin) * -1
    #         y_change = 0
    #     if event.key == pygame.K_RIGHT:
    #         x_change = (segment_width + segment_margin)
    #         y_change = 0
    #     if event.key == pygame.K_UP:
    #         x_change = 0
    #         y_change = (segment_height + segment_margin) * -1
    #     if event.key == pygame.K_DOWN:
    #         x_change = 0
    #         y_change = (segment_height + segment_margin)


pygame.quit()
