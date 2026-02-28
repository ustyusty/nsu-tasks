import numpy as np
import matplotlib.pyplot as plt

size =30

data = np.random.choice([0, 1], size=(size, size), p=[0.8, 0.2])
fig, ax = plt.subplots()
image = ax.imshow(data, cmap='binary')
plt.ion()

is_paused = False
is_active = True

def on_key(event):
    if event.key ==' ':
        global is_paused
        is_paused = not is_paused
    
def on_close(event):
    global is_active
    is_active = False

def on_click(event):
    if event.inaxes == ax:
        ix, iy = int(round(event.xdata)), int(round(event.ydata))
        data[iy, ix] = 1 if data[iy, ix] == 0 else 0
        image.set_data(data)
        fig.canvas.draw_idle()

fig.canvas.mpl_connect('close_event', on_close)
fig.canvas.mpl_connect('key_press_event', on_key)
fig.canvas.mpl_connect('button_press_event', on_click)

# def center_of_sub_arr(arr: np.ndarray, center_x: int, center_y: int, size_x:int, size_y:int) -> np.ndarray:
#     sub_arr = np.zeros((size_y, size_x), dtype=arr.dtype)
#     new_arr = arr[int(center_y-size_y/2):int(center_y+size_y/2), int(center_x-size_x/2):int(center_x+size_x/2)]
#     sub_arr[:new_arr.shape[0],:new_arr.shape[1]] = new_arr
#     return sub_arr


while is_active:
    if not is_paused:
        new_data = data.copy()
        for i in range(size):
            for j in range(size):
                # count = np.sum(center_of_sub_arr(data, j,i,3,3)) - data[i, j]
                count = np.sum(data[i-1:i+2, j-1:j+2]) - data[i, j]
                if data[i][j]:
                    if count<2 or count>3:
                        new_data[i, j] = 0
                else:
                    if count==3:
                        new_data[i, j] = 1
        data[:] = new_data[:]
    image.set_data(data)
    plt.pause(0.1)
    