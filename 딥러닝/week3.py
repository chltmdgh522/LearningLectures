import matplotlib.pyplot as plt
from keras.datasets import mnist
import numpy as np


(train_images, train_labels), (test_images, test_labels) = mnist.load_data()

digit = train_images[0]
plt.imshow(digit, cmap=plt.cm.binary)
plt.show()

my_slice = train_images[10:100]
print(my_slice.shape)

print(train_images.shape)

print(train_labels)
