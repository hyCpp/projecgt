import xdrlib
import xlrd
import xlwt
import sys

def merge_excel(after_file,before_file):
    before_data = xlrd.open_workbook(before_file)
    before_table = before_data.sheets()[0]
    before_nrows = before_table.nrows
    before_ncols = before_table.ncols
    
    after_data = xlrd.open_workbook(after_file)
    after_table = after_data.sheets()[0]
    after_nrows = after_table.nrows
    after_ncols = after_table.ncols

    new_table = xlwt.Workbook()

    sheet = new_table.add_sheet(u'sheet1',cell_overwrite_ok=True)
    row0 = [before_table.row(0)[0].value,before_table.row(0)[1].value,before_table.row(0)[2].value,before_table.row(0)[3].value]

    for i in range(0,len(row0)):
        sheet.write(0,i,row0[i])

    n = after_nrows + before_nrows - 1

    for i in range(1, n):
        sheet.write(i, 0, i)

    for i in range(1, before_nrows):
       for j in range(1, before_ncols):
           sheet.write(i, j, before_table.row(i)[j].value)

    for i in range(1, after_nrows):
       for j in range(1, after_ncols):
           sheet.write(i + before_nrows - 1, j, after_table.row(i)[j].value)

    new_table.save('/home/huyang/myTest/config/new.xlsx')

    return

