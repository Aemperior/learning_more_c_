import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import sys

def plot_data(filename, plot_type='hist'):
    # Read data from file into pandas DataFrame
    data = pd.read_csv(filename, header=None)

    # Create figure and axis
    fig, ax = plt.subplots()

    # Plot data
    if plot_type == 'hist':
        sns.histplot(data[0], kde=False, ax=ax)
    elif plot_type == 'kde':
        sns.kdeplot(data[0], ax=ax)
    else:
        print(f'Unknown plot type: {plot_type}')
        sys.exit(1)

    # Display plot
    plt.show()

# Use the function
plot_data('yourfile.txt', 'hist')  # change 'yourfile.txt' to your actual file name
# For KDE plot, use: plot_data('yourfile.txt', 'kde')
