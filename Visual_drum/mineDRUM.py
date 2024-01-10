import pygame
import pyaudio
import numpy as np

pygame.init()

# Set up the Pygame window
window_width, window_height = 300,128
window = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption("Amplitude Visualization")

# Colors
WHITE = (255, 255, 255)
RED = (255, 0, 0)

# Function to capture audio and calculate amplitude
def get_amplitude(stream):
    data = np.frombuffer(stream.read(CHUNK), dtype=np.int16)
    return np.max(data)

# Main loop
CHUNK = 1024
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100

p = pyaudio.PyAudio()
stream = p.open(format=FORMAT,
                channels=CHANNELS,
                rate=RATE,
                input=True,
                frames_per_buffer=CHUNK)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Get amplitude value from the microphone input
    amplitude = get_amplitude(stream)

    # Clear the screen
    window.fill(WHITE)

    # Draw UI string based on the amplitude value
    x = window_width // 2
    y = window_height // 2
    string_length = 200
    string_height = 2
    string_pos = y + amplitude // 50  # Scale the amplitude for better visualization

    pygame.draw.line(window, RED, (x, y), (x, string_pos), string_height)

    # Display the amplitude value
    font = pygame.font.Font(None, 36)
    text_surface = font.render(f"Amplitude: {amplitude}", True, RED)
    window.blit(text_surface, (20, 20))

    # Update the display
    pygame.display.flip()

    # Adjust the FPS (optional)
    pygame.time.Clock().tick(60)

# Close the stream and quit the Pygame application
stream.stop_stream()
stream.close()
p.terminate()
pygame.quit()
