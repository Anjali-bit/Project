  import pygame
import math

# Initialize Pygame
pygame.init()

# Set up the window
width, height = 800, 600
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("String Movement UI")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# String properties
string_length = 300
amplitude = 100
frequency = 0.02
time = 0

# Main game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Clear the screen
    window.fill(BLACK)

    # Calculate string position
    y = height // 2 + amplitude * math.sin(frequency * time)

    # Draw the string
    pygame.draw.line(window, WHITE, (0, y), (width, y), 2)

    # Update time
    time += 1

    # Update the display
    pygame.display.flip()

# Quit the program
pygame.quit()