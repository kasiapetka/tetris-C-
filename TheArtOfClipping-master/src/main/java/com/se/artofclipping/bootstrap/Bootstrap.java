package com.se.artofclipping.bootstrap;

import com.se.artofclipping.model.Role;
import com.se.artofclipping.model.Service;
import com.se.artofclipping.model.User;
import com.se.artofclipping.repositories.RoleRepository;
import com.se.artofclipping.repositories.ServiceRepository;
import com.se.artofclipping.repositories.UserRepository;
import lombok.extern.slf4j.Slf4j;
import org.springframework.context.ApplicationListener;
import org.springframework.context.event.ContextRefreshedEvent;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Component;
import org.springframework.transaction.annotation.Transactional;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

@Slf4j
@Component
public class Bootstrap implements ApplicationListener<ContextRefreshedEvent> {

    private final RoleRepository roleRepository;
    private final UserRepository userRepository;
    private final ServiceRepository serviceRepository;
    private final BCryptPasswordEncoder bCryptPasswordEncoder;

    public Bootstrap(RoleRepository roleRepository, UserRepository userRepository,
                     ServiceRepository serviceRepository, BCryptPasswordEncoder bCryptPasswordEncoder) {
        this.roleRepository = roleRepository;
        this.userRepository = userRepository;
        this.serviceRepository = serviceRepository;
        this.bCryptPasswordEncoder = bCryptPasswordEncoder;
    }

    @Override
    @Transactional
    public void onApplicationEvent(ContextRefreshedEvent contextRefreshedEvent){
        log.debug("Loading bootstrap data.");
        roleRepository.saveAll(getRoles());
        userRepository.saveAll(getAdmins());
        userRepository.saveAll(getCustomers());
        serviceRepository.saveAll(getServices());
    }

    private List<Role> getRoles(){
        List<Role> roles = new ArrayList<>();

        Role adminRole = new Role();
        adminRole.setId(1L);
        adminRole.setRole("ADMIN");

        roles.add(adminRole);

        Role employeeRole = new Role();
        employeeRole.setRole("EMPLOYEE");
        employeeRole.setId(2L);

        roles.add(employeeRole);

        Role customerRole = new Role();
        customerRole.setRole("CUSTOMER");
        customerRole.setId(3L);

        roles.add(customerRole);

        return roles;
    }

    private List<User> getAdmins(){
        List<User> admins = new ArrayList<>();

        User admin = new User();
        admin.setEmail("admin@admin.com");
        admin.setPassword(bCryptPasswordEncoder.encode("admin"));
        admin.setActive(1);
        admin.setId(1L);
        admin.setName("AdminName");
        admin.setSurname("AdminSurname");

        Role userRole = roleRepository.findByRole("ADMIN");
        admin.setRoles(new HashSet<>(Arrays.asList(userRole)));

        admins.add(admin);

        return admins;
    }

    private List<User> getCustomers(){
        List<User> customers = new ArrayList<>();

        User customer = new User();
        customer.setEmail("aaa@aaa.com");
        customer.setPassword(bCryptPasswordEncoder.encode("aaa"));
        customer.setActive(1);
        customer.setName("aaa");
        customer.setSurname("aaa");

        Role userRole = roleRepository.findByRole("CUSTOMER");
        customer.setRoles(new HashSet<>(Arrays.asList(userRole)));

        customers.add(customer);

        return customers;
    }

    private List<Service> getServices(){
        List<Service> services = new ArrayList<>();

        // Male services
        Service service = new Service();
        service.setName("Haircut");
        service.setIsActive(true);
        service.setDurationMinutes(30);
        service.setPrice(40D);
        service.setType(Character.toUpperCase('M'));
        services.add(service);

        service = new Service();
        service.setName("Beardcut");
        service.setIsActive(true);
        service.setDurationMinutes(30);
        service.setPrice(40D);
        service.setType(Character.toUpperCase('M'));
        services.add(service);

        service = new Service();
        service.setName("Combo (beard+Hair)");
        service.setIsActive(true);
        service.setDurationMinutes(60);
        service.setPrice(70D);
        service.setType(Character.toUpperCase('M'));
        services.add(service);

        // Female services
        service = new Service();
        service.setName("Haircut");
        service.setIsActive(true);
        service.setDurationMinutes(30);
        service.setPrice(40D);
        service.setType(Character.toUpperCase('F'));
        services.add(service);

        service = new Service();
        service.setName("Color");
        service.setIsActive(true);
        service.setDurationMinutes(90);
        service.setPrice(80D);
        service.setType(Character.toUpperCase('F'));
        services.add(service);

        service = new Service();
        service.setName("Haircut + Stylisation");
        service.setIsActive(true);
        service.setDurationMinutes(120);
        service.setPrice(120D);
        service.setType(Character.toUpperCase('F'));
        services.add(service);

        return services;
    }
}
