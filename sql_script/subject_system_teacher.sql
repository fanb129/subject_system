create table teacher
(
    tno      varchar(50) not null comment '教师编号'
        primary key,
    tname    varchar(50) not null comment '教师名',
    tsex     varchar(10) not null comment '教师性别',
    password varchar(50) not null comment '教师密码'
);

INSERT INTO subject_system.teacher (tno, tname, tsex, password) VALUES ('root', 'root', 'man', '123');
INSERT INTO subject_system.teacher (tno, tname, tsex, password) VALUES ('t1001', 'zhangs', 'man', '123');
INSERT INTO subject_system.teacher (tno, tname, tsex, password) VALUES ('t1002', 'hah', 'man', '123');