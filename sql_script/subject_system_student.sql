create table student
(
    sno      varchar(50) not null comment '学号'
        primary key,
    sname    varchar(50) not null comment '姓名',
    sex      varchar(10) not null comment '性别',
    password varchar(50) not null comment '密码'
);

INSERT INTO subject_system.student (sno, sname, sex, password) VALUES ('s1001', '张三', 'man', '123');
INSERT INTO subject_system.student (sno, sname, sex, password) VALUES ('s1002', 'lisi', 'man', '123');
INSERT INTO subject_system.student (sno, sname, sex, password) VALUES ('s1004', 'zhaoliu', 'man', '123');