import pygame
from random import randint

# --- Globals ---
# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREY = (100, 100, 100)
GREEN = (0, 255, 0)
WHITE_GREEN = (150, 255, 150)
BLACK_GREEN = (50, 100, 50)
RED_GREEN = (255, 255, 0)
colors = [RED, RED_GREEN, WHITE, WHITE_GREEN, BLACK, BLACK_GREEN]

segment_margin = 3
segment_width = 100
segment_height = 100
offset = 50


class Segment(pygame.sprite.Sprite):
    """ Class to represent one segment of the board. """
    # -- Methods
    # Constructor function

    def __init__(self, x, y, color):
        # Call the parent's constructor
        super().__init__()

        # Set height, width
        self.image = pygame.Surface([segment_width - segment_margin,
                                     segment_height - segment_margin])
        self.image.fill(color)

        # Make our top-left corner the passed-in location.
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y


def draw_arrows(screen):
    arrowImg = pygame.image.load('arrow.png')
    arrow_width = arrowImg.get_width()
    screen.blit(arrowImg, (offset - arrow_width, offset))
    screen.blit(arrowImg, (screen.get_width() - offset, offset))
    arrowImg = pygame.transform.rotate(arrowImg, 90)
    screen.blit(arrowImg, (offset, offset - arrow_width))
    screen.blit(arrowImg, (offset, screen.get_width() - offset))
    arrowImg = pygame.transform.rotate(arrowImg, 90)
    screen.blit(arrowImg, (offset - arrow_width,
                           screen.get_width() - 2 * offset))
    screen.blit(arrowImg, (screen.get_width() - offset,
                           screen.get_width() - 2 * offset))


def draw_board(screen, board):

    allspriteslist = pygame.sprite.Group()

    # Create an initial snake
    snake_segments = []
    for i, line in enumerate(board):
        for j, color in enumerate(line):
            y = i * (segment_height) + offset + segment_margin / 2
            x = j * (segment_width) + offset + segment_margin / 2
            allspriteslist.add(Segment(x, y, colors[color]))

    # Clear screen
    screen.fill(GREY)

    allspriteslist.draw(screen)
    draw_arrows(screen)

    # Flip screen
    pygame.display.flip()
