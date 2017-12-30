import datetime

cases = int(input())

for i in range(cases):

	start_date = str(input())
	
	start_date = start_date[0:2] + "/" + start_date[2:4] + "/" + start_date[4:8]

	date_1 = datetime.datetime.strptime(start_date, "%m/%d/%Y")

	end_date = date_1 + datetime.timedelta(days=280)

	day = int(datetime.datetime.strftime(end_date, "%d"))
	month = int(datetime.datetime.strftime(end_date, "%m"))

	if (month == 1 and day >= 21) or (month == 2 and day <= 19):
		sign = "aquarius"
	elif (month == 2 and day >= 20) or (month == 3 and day <= 20):
		sign = "pisces"
	elif (month == 3 and day >= 21) or (month == 4 and day <= 20):
		sign = "aries"
	elif (month == 4 and day >= 21) or (month == 5 and day <= 21):
		sign = "taurus"
	elif (month == 5 and day >= 22) or (month == 6 and day <= 21):
		sign = "gemini"
	elif (month == 6 and day >= 22) or (month == 7 and day <= 22):
		sign = "cancer"
	elif (month == 7 and day >= 23) or (month == 8 and day <= 21):
		sign = "leo"
	elif (month == 8 and day >= 22) or (month == 9 and day <= 23):
		sign = "virgo"
	elif (month == 9 and day >= 24) or (month == 10 and day <= 23):
		sign = "libra"
	elif (month == 10 and day >= 24) or (month == 11 and day <= 22):
		sign = "scorpio"
	elif (month == 11 and day >= 23) or (month == 12 and day <= 22):
		sign = "sagittarius"
	else:
		sign = "capricorn"

	print(str(i + 1) + " " + datetime.datetime.strftime(end_date, "%m/%d/%Y") + " " + sign)
