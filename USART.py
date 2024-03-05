import serial
import csv

ser = serial.Serial('/dev/tty.HC-06-DevB-1', 9600, timeout=None)

with open('/Users/wout/OneDrive/Sudoku.csv', 'r') as infile:
    tabel = [row for row in csv.reader(infile, delimiter=';')]

print(ser.portstr)                                      #Check if connection is good
print(tabel)
data = True
for row in tabel:
    for column in row:
        new_c = column.replace("\ufeff","")             #Startcode csv makes
        if(data):
            ser.write(int(new_c).to_bytes(1, "big"))    #Converts int to a byte (Big Endian)
        data = ser.read(1)                              #Wait for control signal to send next byte                       

ser.close()