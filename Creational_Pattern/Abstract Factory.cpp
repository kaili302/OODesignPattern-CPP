class CPU{
protected:
	int frequence;
	int cores;
public:
	virtual void print() = 0;
};

class CPUFactory{
public:
	virtual CPU* createCPU() = 0;
};

class IntelCPU : public CPU{
public:
	IntelCPU(int frequence, int cores){
		CPU::frequence = frequence;
		CPU::cores = cores;
	}
	virtual void print(){
		cout << "Intel CPU : " << frequence << " GHz, " << cores << " cores" << endl;
	}
};

class AMDCPU : public CPU{
public:
	AMDCPU(int frequence, int cores){
		CPU::frequence = frequence;
		CPU::cores = cores;
	}
	virtual void print(){
		cout << "AMD CPU : " << frequence << " GHz, " << cores << " cores" << endl;
	}
};

class IntelCPUFactory: public CPUFactory{
public:
	virtual CPU* createCPU(){
		return new IntelCPU(3, 4);
	}
};

class AMDCPUFactory: public CPUFactory{
public:
	virtual CPU* createCPU(){
		return new AMDCPU(3, 4);
	}
};