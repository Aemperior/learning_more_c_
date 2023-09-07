import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import sys
import numpy as np

l_min = 5.0
l1 = 17.23
l2 = 82.36
q = 0.44
def pdf(l):
    return q*(1/l1)*np.exp(-(l-l_min)/l1) + (1-q)*(1/l2)*np.exp(-(l-l_min)/l2) # mixture exponential pdf (not cumulative, just pdf)

filename = "random_nums.txt"
plot_type = "kde"
# Read data from file into pandas DataFrame
data = pd.read_csv(filename, header=None)
# Create figure and axis
fig, ax = plt.subplots()
# Plot data
if plot_type == 'hist':
    sns.histplot(data[0], kde=False, ax=ax, stat="density")
elif plot_type == 'kde':
    sns.kdeplot(data[0], ax=ax, bw_adjust=0.2)
else:
    print(f'Unknown plot type: {plot_type}')
    sys.exit(1)


l_values = np.linspace(0.1, 500, 1000)

pdf_values = pdf(l_values)

ax.plot(l_values, pdf_values)

plt.show()