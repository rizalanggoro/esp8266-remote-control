String current_state = "";

void parser(String data) {
  if (current_state != data) {
    current_state = data;

    String d = current_state;

    if (d == "F") _forward();
    else if (d == "B") _backward();
    else if (d == "R") _right();
    else if (d == "L") _left();
    else if (d == "I") _forwardRight();
    else if (d == "G") _forwardLeft();
    else if (d == "J") _backwardRight();
    else if (d == "H") _backwardLeft();
    else if (d == "S") _stop();

    else if (d == "0") _changeSpeedB(70);
    else if (d == "1") _changeSpeedB(73);
    else if (d == "2") _changeSpeedB(76);
    else if (d == "3") _changeSpeedB(79);
    else if (d == "4") _changeSpeedB(82);
    else if (d == "5") _changeSpeedB(85);
    else if (d == "6") _changeSpeedB(88);
    else if (d == "7") _changeSpeedB(91);
    else if (d == "8") _changeSpeedB(94);
    else if (d == "9") _changeSpeedB(97);
    else if (d == "q") _changeSpeedB(100);

    //    Serial.println(d);
  }
}

void _forward() {
  Serial.println("forward");
  _changeMotorB(true);
}

void _backward() {
  Serial.println("backward");
  _changeMotorB(false);
}

void _right() {
  Serial.println("right");
  _changeMotorA(true);
}

void _left() {
  Serial.println("left");
  _changeMotorA(false);
}

void _forwardRight() {
  _changeMotorA(true);
  _changeMotorB(true);
}

void _forwardLeft() {
  _changeMotorA(false);
  _changeMotorB(true);
}

void _backwardRight() {
  _changeMotorA(true);
  _changeMotorB(false);
}

void _backwardLeft() {
  _changeMotorA(false);
  _changeMotorB(false);
}

void _stop() {
  Serial.println("stop");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void _changeMotorA(bool is_right) {
  digitalWrite(in1, is_right ? HIGH : LOW);
  digitalWrite(in2, is_right ? LOW : HIGH);
}

void _changeMotorB(bool is_forward) {
  digitalWrite(in3, is_forward ? LOW : HIGH);
  digitalWrite(in4, is_forward ? HIGH : LOW);
}

void _changeSpeedB(float percent) {
  float value = ((float) percent / 100.0) * 255.0;
  int value1 = value;
  analogWrite(enb, value1);
  Serial.println(value1);
}
