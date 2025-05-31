import pygame
import sys

pygame.init()

WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Winter Scene")

WHITE = (255, 255, 255)
BLUE = (135, 206, 235)
BLACK = (0, 0, 0)
ORANGE = (255, 165, 0)
RED = (255, 0, 0)

def draw_snowman(x, y):
    pygame.draw.circle(screen, WHITE, (x, y), 30)
    pygame.draw.circle(screen, WHITE, (x, y-50), 20)
    pygame.draw.circle(screen, WHITE, (x, y-80), 15)
    

clock = pygame.time.Clock()
angle = 0
plane_x = 800

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    angle += 2
    plane_x -= 3
    if plane_x < -50:
        plane_x = 800

    screen.fill(BLUE)
    
    draw_snowman(200, 500)
    draw_snowman(600, 500)
    
    snowflake = pygame.Surface((30, 30), pygame.SRCALPHA)
    pygame.draw.line(snowflake, WHITE, (15, 0), (15, 30), 2)
    pygame.draw.line(snowflake, WHITE, (0, 15), (30, 15), 2)
    pygame.draw.line(snowflake, WHITE, (5, 5), (25, 25), 2)
    pygame.draw.line(snowflake, WHITE, (5, 25), (25, 5), 2)
    rotated = pygame.transform.rotate(snowflake, angle)
    screen.blit(rotated, (385, 285))
    
    pygame.draw.polygon(screen, RED, [
        (plane_x, 100),
        (plane_x+40, 120),
        (plane_x, 140)
    ])
    
    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()