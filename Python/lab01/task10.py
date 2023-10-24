class ElectronicDevice:
    def __init__(self, sn, brand, model, internal_memory):
        self.serial_number = sn
        self.brand = brand
        self.model = model
        self.internal_memory = internal_memory
    
    def show_device_info(self):
        return f"You have electronic device {self.brand} {self.model} with {self.internal_memory}GB memory"
    
    def show_storage_info(self):
        return f"Your device has {self.internal_memory}GB"
    
    def __str__(self):
        return f"{self.serial_number}, {self.brand}, {self.model}, {self.internal_memory}"
    
    def __repr__(self):
        return f"ElectronicDevice({self.serial_number}, {self.brand}, {self.model}, {self.internal_memory})"

class Smartphone(ElectronicDevice):
    def __init__(self, sn, brand, model, internal_memory, main_camera_quality, installed_apps=[]):
        super().__init__(sn, brand, model, internal_memory)
        self.available_storage = internal_memory
        self.main_camera_quality = main_camera_quality
        self.installed_apps = installed_apps
    
    def show_device_info(self):
        return f"You have smartphone {self.brand} {self.model} with {self.internal_memory}GB memory and {self.main_camera_quality}MP camera"
    
    def show_storage_info(self):
        return f"Your smartphone has {self.available_storage}GB available storage out of {self.internal_memory}GB"
    
    def install_app(self, app_name, space_needed):
        msg = ""
        if self.available_storage >= space_needed:
            self.installed_apps.append(app_name)
            self.available_storage -= space_needed
            msg = f"You successfully installed {app_name}"
        else:
            msg = f"Seems like you don't have enough space. Available storage space: {self.available_storage}GB" 
 
        return msg
    
    def __str__(self):
        return f"{self.serial_number}, {self.brand}, {self.model}, {self.internal_memory}, {self.main_camera_quality}, {self.installed_apps}"
    
    def __repr__(self):
        return f"Smartphone({self.serial_number}, {self.brand}, {self.model}, {self.internal_memory}, {self.main_camera_quality}, {self.installed_apps})"
        
class Laptop(ElectronicDevice):
    def __init__(self, sn, brand, model, internal_memory, processor, processor_version):
        super().__init__(sn, brand, model, internal_memory)
        self.processor = processor
        self.processor_version = processor_version
        
    def show_device_info(self):
        return f"You have laptop {self.brand} {self.model} with {self.internal_memory}GB memory and {self.processor} {self.processor_version} processor"
    
    def show_storage_info(self):
        return f"Your laptop has {self.internal_memory}GB"
    
    def connect_device(self, device_name):
        return f"You just connected {device_name} to {self.brand} {self.model}"

    def __str__(self):
        return f"{self.serial_number}, {self.brand}, {self.model}, {self.internal_memory}, {self.processor}, {self.processor_version}"
    
    def __repr__(self):
        return f"Laptop({self.serial_number}, {self.brand}, {self.model}, {self.internal_memory}, {self.processor}, {self.processor_version})"
# Tests:

# ElectronicDevice tests
test_electronic_device = ElectronicDevice("8vef15c6", "TestBrand", "TestModel", 128)
assert test_electronic_device.serial_number == "8vef15c6"
assert test_electronic_device.brand == "TestBrand"
assert test_electronic_device.model == "TestModel"
assert test_electronic_device.internal_memory == 128
assert test_electronic_device.show_device_info() == "You have electronic device TestBrand TestModel with 128GB memory"
assert test_electronic_device.show_storage_info() == "Your device has 128GB"

# # Smarthphone tests
assert issubclass(Smartphone, ElectronicDevice)
test_smartphone = Smartphone("9pol23k7", "TestBrand2", "TestModel2", 256, main_camera_quality=13)
assert test_smartphone.serial_number == "9pol23k7"
assert test_smartphone.brand == "TestBrand2"
assert test_smartphone.model == "TestModel2"
assert test_smartphone.internal_memory == 256
assert test_smartphone.available_storage == 256
assert test_smartphone.main_camera_quality == 13
assert test_smartphone.installed_apps == []
assert test_smartphone.show_device_info() == "You have smartphone TestBrand2 TestModel2 with 256GB memory and 13MP camera"
res1 =  test_smartphone.install_app("TestApp", 56)
assert res1 == "You successfully installed TestApp"
assert len(test_smartphone.installed_apps) == 1
assert "TestApp" in test_smartphone.installed_apps
assert test_smartphone.show_storage_info() == "Your smartphone has 200GB available storage out of 256GB"
res2 = test_smartphone.install_app("TestApp2", 201)
assert res2 == "Seems like you don't have enough space. Available storage space: 200GB"
assert len(test_smartphone.installed_apps) == 1
assert "TestApp2" not in test_smartphone.installed_apps 

# # Laptop tests
assert issubclass(Laptop, ElectronicDevice)
test_laptop = Laptop("7yeu14t3", "TestBrand3", "TestModel3", 512, "TestProcessor", "v5.2.1.13")
assert test_laptop.serial_number == "7yeu14t3"
assert test_laptop.brand == "TestBrand3"
assert test_laptop.model == "TestModel3"
assert test_laptop.internal_memory == 512
assert test_laptop.processor == "TestProcessor"
assert test_laptop.processor_version == "v5.2.1.13"
assert test_laptop.show_device_info() == "You have laptop TestBrand3 TestModel3 with 512GB memory and TestProcessor v5.2.1.13 processor"
assert test_laptop.show_storage_info() == "Your laptop has 512GB"
assert test_laptop.connect_device("TestConnectedDevice") == "You just connected TestConnectedDevice to TestBrand3 TestModel3"

"✅ All OK! +2.0 points"