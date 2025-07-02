#include <iostream>
#include <vector>

enum class IceWarning {
  Warning,
  NoWarning,
  Invalid,
};



std::string ice_warning_to_string(IceWarning warning)  {
  if (warning == IceWarning::Warning) {
    return "Glatteis";
  } else {
    return "";
  }
}


 /*
 * std::string warning_string1 = ice_warning_to_string(IceWarning::Warning)   // string: "Glatteis"
 * std::string warning_string2 = ice_warning_to_string(IceWarning::NoWarning) // string: ""
 * std::string warning_string3 = ice_warning_to_string(IceWarning::Invalid)   string: ""
 */ 



 struct stimulus_response_t {
 IceWarning stimulus;
 std::string response;
};

int main() {
  std::vector<stimulus_response_t> warnings{
    {IceWarning::Warning, "Glatteis" }, 
    {IceWarning::NoWarning,"" },
    {IceWarning::Invalid, ""},   
  };

  for (stimulus_response_t stimulus_response : warnings) {
    std::string warning = ice_warning_to_string(stimulus_response.stimulus) ;
    //auto warning = ice_warning_to_string(stimulus_response.stimulus) ; alternative
    
    std::cout << "ice_warning_to_string() ";
    if (warning == stimulus_response.response) {
      std::cout << "OK";
    } else {
      std::cout << "not OK";
    }
    std::cout << "\n";
  }

  return 0;
}
