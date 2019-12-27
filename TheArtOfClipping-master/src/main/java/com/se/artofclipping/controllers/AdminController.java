package com.se.artofclipping.controllers;

import com.se.artofclipping.model.User;
import com.se.artofclipping.services.AdminService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;

@Slf4j
@Controller
public class AdminController {

    AdminService adminService;

    public AdminController(AdminService adminService) {
        this.adminService = adminService;
    }

    @GetMapping("admin/adminpage")
    public String adminPage(){
        return "admin/adminpage";
    }

    @GetMapping("admin/addhairdresser")
    public String addHairdresser(Model model){
        model.addAttribute("user", new User());

        return "admin/addHairdresser";
    }

    @PostMapping("admin/register")
    public String register(@ModelAttribute User user, Model model){
        log.debug(user.getEmail());
        User userExists = adminService.findUserByEmail(user.getEmail());
        if (userExists != null) {
            log.debug("User already exists.");
        }

            adminService.saveHairdresser(user);
            model.addAttribute("user", new User());

        log.debug("REGISTERED SUCCESSFULLY FFS");

        return "admin/adminpage";
    }

    @GetMapping("admin/listhairdressers")
    public String list(Model model){

        model.addAttribute("hairdressers", adminService.listHairdressers());

        return "admin/list";
    }
}
