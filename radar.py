import serial  # python -m pip install pyserial (sudo easy_install pip)
import turtle  
def main():
    gr = turtle.Turtle()                    
    gr.pensize(5)                           
    gr.hideturtle()                         
    gr.color("green")                       
    gr.speed(1000)                          
    ser = serial.Serial()                   
    ser.baudrate = 9600                     
    ser.port = "COM3"                       
    ser.open()                              
    while ser.is_open:                      

      line = ser.readline()                 
      data = line.split()                  
      angle = int(data[0])                  
      distance = int(data[1]) * 10          
      if (angle == 0):                      
          gr.clear()                        
      gr.seth(angle)                        
      gr.fd(distance)                       
      gr.bk(distance)                       

if __name__ == '__main__':
    main()
