import re
import sys


image_change_speed = 6000  # Higher value = slower animation speed.
totalFrames = 40

# Scale colors to fit in PWM space.
# Adjust for eye's relative sensitivity to each color.
denominator_r = 256 / totalFrames
denominator_g = 256 / (totalFrames - 10)
denominator_b = 256 / (totalFrames + 10)

num_images = 0

red_all = []
green_all = []
blue_all = []

for file in sys.argv[1:]:
    num_images += 1

    red_frame = []
    green_frame = []
    blue_frame = []

    for line in open(file):
        if not re.match("^0x", line):
            continue

        line = line.strip()
        line = line.replace(" ", "")
        lineAry = line.split(",")

        red_row = []
        green_row = []
        blue_row = []

        for pixel in lineAry:
            if pixel == "":
                continue

            b = round(int(pixel[4:6], 16) / denominator_b)
            g = round(int(pixel[6:8], 16) / denominator_g)
            r = round(int(pixel[8:10], 16) / denominator_r)

            red_row.append(r)
            green_row.append(g)
            blue_row.append(b)

        red_frame.append(red_row)
        green_frame.append(green_row)
        blue_frame.append(blue_row)

    red_all.append(red_frame)
    green_all.append(green_frame)
    blue_all.append(blue_frame)


change_image_frames = -1
if num_images > 1:
    change_image_frames = image_change_speed


print("\n*** Copy/paste below data structures into 'Data to Display' section of source code. ***\n\n")

print("#define numImages {}  // >1 means animation.".format(num_images))
print("#define changeImageFrames {}  // Animation control. Set to -1 to display a single image.  Larger number == longer delay between image changes.\n".format(change_image_frames))

print("__RODATA(Flash2) const unsigned short int brightnessR[numImages][32][32] = {};\n".format(str(red_all).replace('[','{').replace(']','}')))
print("__RODATA(Flash2) const unsigned short int brightnessG[numImages][32][32] = {};\n".format(str(green_all).replace('[','{').replace(']','}')))
print("__RODATA(Flash2) const unsigned short int brightnessB[numImages][32][32] = {};\n".format(str(blue_all).replace('[','{').replace(']','}')))
