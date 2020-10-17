# System block diagram

![system_bd](mermaid/system_bd.png "System block diagram")

## Power block diagram

![power_bd](mermaid/power_bd.png "Power block diagram")

## Control Signal block diagram

![control_signal_bd](mermaid/control_signal_bd.png "Control signal block diagram")

## Software block diagram

![software_bd](mermaid/software_bd.png "Software block diagram")

### Firmware

![firmware_bd](mermaid/firmware_bd.png "Firmware block diagram")

#### Network Loop (10 Hz)

![network_loop_bd](mermaid/network_loop_bd.png "Network loop block diagram")

Supported requests:
* **GetMotorState (MotorNumber)**
    * Position (rad)
    * Velocity (rad/s)
    * Acceleration (rad^2/s)
* **SetMotorSetpoint (MotorNumber, PositionSetpoint)**
* **GetMotorPID**
* **SetMotorPID**
* SendNewTrajectory
* GetTrajectoryState
* ExecuteTrajectory
* AbortTrajectory
* SetLogLevel
* **GetLogMsgs**

#### Control Loop (100 Hz)

![control_loop_bd](mermaid/control_loop_bd.png "Control loop block diagram")