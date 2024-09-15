class Integer {
    int m_Value{ 0 };
public:
    Integer() = default;

    Integer(int value) {
        m_Value = value;
    }

    Integer(const Integer&) = delete;

    void SetValue(int value) {
        m_Value = value;
    }

    void SetValueFromFloat(float value) {
        // Handle float value explicitly
        m_Value = static_cast<int>(value);
    }

    void SetValue(float) = delete; // Keep deleted to prevent implicit calls
};
int main() { 
	Integer i1; 
	i1.SetValue(5);
	//Error as SetValue(float) is deleted
	i1.SetValueFromFloat(67.1f);
	return 0;
}