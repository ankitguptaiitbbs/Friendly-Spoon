KTOL_MULTIPLIER = 2.20462
LTOK_MULTIPLIER = 0.453592

weight = float(input("Weight: "))
unit = input("(K)g or (L)bs: ").upper()

converted_weight = weight
if unit == "L":
    converted_weight *= LTOK_MULTIPLIER
    print("Weight in Kg: {}".format(converted_weight))
elif unit == "K":
    converted_weight *=  KTOL_MULTIPLIER
    print("Weight in Lbs: {}".format(converted_weight))
else:
    print("Conversion Failed! Wrong Input!")