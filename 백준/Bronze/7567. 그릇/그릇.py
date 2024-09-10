height = 10

plates = input()

for prev_plate, plate in zip(plates, plates[1:]):
    if plate != prev_plate:
        height += 10
    else:
        height += 5

print(height)
