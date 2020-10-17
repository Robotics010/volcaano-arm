# System block diagram

```mermaid
graph TD;

ps["power supply"]
ebox["electronics box"]
arm["robotic arm"]
pc["personal computer"]

ps --"12V DC"--> ebox
ps --"5V DC"--> ebox

pc --"request USB"--> ebox
ebox --"response USB"--> pc

ebox --"motor conotrol"--> arm
arm --"motor feedback"--> ebox

```

## Power block diagram

```mermaid
graph LR;

ps["power supply"]
subgraph ebox["electronics box"]
    d1["driver 1"]
    d2["driver 2"]
    d3["driver 3"]
    ctr["controller"]
    t4["terminal 4"]
    t5["terminal 5"]
end

ps --"5V DC"--> ctr
ps --"12V DC"--> d1
ps --"12V DC"--> d2
ps --"12V DC"--> d3
ps --"12V DC"--> t4
ps --"12V DC"--> t5

subgraph arm["robotic arm"]
    m1["motor 1"]
    m2["motor 2"]
    m3["motor 3"]
    m4["motor 4"]
    m5["motor 5"]
end

d1 --"power control"--> m1

d2 --"power control"--> m2

d3 --"power control"--> m3

t4 --"power"--> m4

t5 --"power"--> m5

```

## Control Signal block diagram

```mermaid
graph LR;

subgraph ebox["electronics box"]
    d1["driver 1"]
    d2["driver 2"]
    d3["driver 3"]
    ctr["controller"]
end

subgraph arm["robotic arm"]
    m1["motor 1"]
    m2["motor 2"]
    m3["motor 3"]
    m4["motor 4"]
    m5["motor 5"]
end

m1 --"feedback"--> ctr
ctr --"control signal"--> d1

m2 --"feedback"--> ctr
ctr --"control signal"--> d2

m3 --"feedback"--> ctr
ctr --"control signal"--> d3

m4 --"feedback"--> ctr
ctr --"control signal"--> m4_2

m5--"feedback"--> ctr
ctr --"control signal"--> m5_2

subgraph arm_2["robotic arm"]
    m4_2["motor 4"]
    m5_2["motor 5"]
end

```

## Software block diagram

```mermaid
graph LR;

subgraph pc["personal computer"]
    demo["demo software"]
    usr["user-defined application"]
    api["C++/python API"]
    pc_usb["usb"]
end

demo <--> api
usr <--> api

api <--> pc_usb

subgraph ctl["controller"]
    fw["firmware"]
    fw_usb["usb"]
end

pc_usb <--> fw_usb

fw_usb <--> fw

```

### Firmware

```mermaid
graph TD;

subgraph fw["firmware"]
    init["initialization"]
    subgraph proc["process loop"]
        l10["Network Loop (10 Hz)"]
        vars["Value Table"]
        l100["Control Loop (100 Hz)"]
    end
    shut["shutdown"]
end

l10 -->  vars --> l10
l100 --> vars --> l100


```

#### Network Loop (10 Hz)

```mermaid
graph LR;

subgraph l10["Network Loop (10 Hz)"]
    proc["process request"]

    usb_i["usb"]
    usb_o["usb"]

    usb_i --"request"--> proc
    proc --"response"--> usb_o
end

```

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

```mermaid
graph LR;

subgraph l100["Control Loop (100 Hz)"]
    proc["PID controller"]

    f["motor feedback"]
    c["driver control"]
    s["position setpoint"]

    f --"input"--> proc
    s --"setpoint"--> proc
    proc --"output"--> c
end

```