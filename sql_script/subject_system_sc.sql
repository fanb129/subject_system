create table sc
(
    sno   varchar(50) not null comment '学号',
    cno   varchar(50) not null comment '课程号',
    grade varchar(50) null comment '成绩'
);

INSERT INTO subject_system.sc (sno, cno, grade) VALUES ('s1001', 'c1003', '99');
INSERT INTO subject_system.sc (sno, cno, grade) VALUES ('s1001', 'c1001', '60');
INSERT INTO subject_system.sc (sno, cno, grade) VALUES ('s1002', 'c1001', '88');
INSERT INTO subject_system.sc (sno, cno, grade) VALUES ('s1003', 'c1001', '66');