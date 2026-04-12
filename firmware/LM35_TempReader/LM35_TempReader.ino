// ---------------------------------------------------------
// Tên dự án: Hệ thống giám sát nhiệt độ LM35
// Tệp tin:   LM35_TempReader.ino
// Chức năng: Đọc giá trị nhiệt độ từ cảm biến LM35 (Kênh A0)
// ---------------------------------------------------------

const int LM35_PIN = A0; // Khai báo chân Analog A0 nối với chân Vout của LM35

void setup() {
  // Khởi tạo giao tiếp Serial với tốc độ baud 9600 để gửi dữ liệu lên PC
  Serial.begin(9600); 
  Serial.println("=== He Thong Giam Sat Nhiet Do LM35 ===");
}

void loop() {
  // Bước 1: Đọc giá trị Analog từ cảm biến (Độ phân giải 10-bit: 0 - 1023)
  int analogValue = analogRead(LM35_PIN);

  // Bước 2: Chuyển đổi giá trị Analog sang điện áp (Volt)
  // Điện áp tham chiếu của Arduino Uno là 5.0V
  float voltage = analogValue * (5.0 / 1023.0);

  // Bước 3: Tính toán nhiệt độ (Độ C)
  // Theo datasheet, độ nhạy của LM35 là 10mV/độ C (tương đương 0.01V/độ C)
  float temperatureC = voltage / 0.01;

  // Bước 4: Gửi định dạng dữ liệu lên phần mềm PC (C#)
  Serial.print("TEMP:"); // Tiền tố để app C# dễ dàng cắt chuỗi (parsing)
  Serial.println(temperatureC);

  // Tạm dừng 1 giây (1000ms) để ổn định hệ thống trước chu kỳ đọc tiếp theo
  delay(1000);
}