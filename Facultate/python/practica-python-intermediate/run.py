import numpy as np
import matplotlib.pyplot as plt

class IntegrateFireNeuron:
    def __init__(self, membrane_time_constant, reset_potential, threshold_potential=1.0):
        self.tau_m = membrane_time_constant
        self.V_rest = 0
        self.V_reset = reset_potential
        self.V_m = self.V_rest
        self.threshold = threshold_potential
        self.spike_times = []

    def integrate(self, time_step, input_curr):
        dV = (self.V_rest - self.V_m + input_curr * self.tau_m) * (time_step / self.tau_m)
        self.V_m += dV
        if self.V_m >= self.threshold:
            self.trigger_and_reset()

    def trigger_and_reset(self):
        self.spike_times.append(self.V_m)
        self.V_m = self.V_reset

def create_constant_input_scenario(ifn, simulation_time, input_current, plot=True):
    time_step = 0.1  # ms
    num_steps = int(simulation_time / time_step)
    voltages = np.zeros(num_steps)
    
    for t in range(num_steps):
        ifn.integrate(time_step, input_current)
        voltages[t] = ifn.V_m
    
    if plot:
        plt.plot(np.arange(num_steps) * time_step, voltages)
        plt.xlabel('Time (ms)')
        plt.ylabel('Membrane Potential (V)')
        plt.title('Constant Input Scenario')
        plt.show()
    
    return voltages

def create_sin_input_scenario(ifn, simulation_time, input_amplitude, plot=True):
    time_step = 0.1  # ms
    num_steps = int(simulation_time / time_step)
    voltages = np.zeros(num_steps)
    input_currents = input_amplitude * np.sin(2 * np.pi * (np.arange(num_steps) * time_step / simulation_time))
    
    for t in range(num_steps):
        ifn.integrate(time_step, input_currents[t])
        voltages[t] = ifn.V_m
    
    if plot:
        plt.plot(np.arange(num_steps) * time_step, voltages)
        plt.xlabel('Time (ms)')
        plt.ylabel('Membrane Potential (V)')
        plt.title('Sinusoidal Input Scenario')
        plt.show()
    
    return voltages

def create_time_dependent_input_scenario(ifn, simulation_time, input_func, plot=True):
    time_step = 0.1  # ms
    num_steps = int(simulation_time / time_step)
    voltages = np.zeros(num_steps)
    
    for t in range(num_steps):
        input_current = input_func(t * time_step)
        ifn.integrate(time_step, input_current)
        voltages[t] = ifn.V_m
    
    if plot:
        plt.plot(np.arange(num_steps) * time_step, voltages)
        plt.xlabel('Time (ms)')
        plt.ylabel('Membrane Potential (V)')
        plt.title('Time-Dependent Input Scenario')
        plt.show()
    
    return voltages

# Define simulation parameters
simulation_time = 100  # ms
input_current = 1.5  # Constant input current
input_amplitude = 1.5  # Amplitude for sinusoidal input

# Initialize instance of IntegrateFireNeuron
neuron = IntegrateFireNeuron(20, -70)

# Run and display constant input scenario
create_constant_input_scenario(neuron, simulation_time, input_current)

# Run and display sinusoidal input scenario
create_sin_input_scenario(neuron, simulation_time, input_amplitude)

# Define a time-dependent input function (example: linear increase)
input_func = lambda t: 0.1 * t  # Linear increase over time

# Run and display time-dependent input scenario
create_time_dependent_input_scenario(neuron, simulation_time, input_func)
