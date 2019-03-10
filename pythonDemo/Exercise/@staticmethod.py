class Date:
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

    @staticmethod
    def format_date(strDate):
        y,m,d = strDate.split("-")
        return Date(int(y), int(m), int(d))

    def yesterday(self):
        self.day -= 1

    def __str__(self):
        return '{}/{}/{}'.format(self.year, self.month, self.day)

newDay = Date.format_date('2018-10-24')
print (newDay)